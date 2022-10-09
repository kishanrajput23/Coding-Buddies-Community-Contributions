import 'dart:typed_data';
import 'dart:ui' as ui;
import 'dart:math' as math;

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:path_drawing/path_drawing.dart';

class SvgWidget extends StatelessWidget {
  const SvgWidget({required this.painters});

  final List<SvgPathPainter> painters;

  @override
  Widget build(BuildContext context) => CustomPaint(painter: SvgPathsPainter(painters, Notifier()));
}

class SvgPathPainter {
  SvgPathPainter._(this._paint);

  factory SvgPathPainter.fill() {
    final Paint paint = Paint()..style = PaintingStyle.fill;
    return SvgPathPainter._(paint);
  }

  factory SvgPathPainter.stroke(double strokeWidth, {StrokeCap? strokeCap, StrokeJoin? strokeJoin, double? strokeMiterLimit}) {
    final Paint paint = Paint()
      ..style = PaintingStyle.fill
      ..strokeWidth = strokeWidth;
    if (strokeCap != null) {
      paint.strokeCap = strokeCap;
    }
    if (strokeJoin != null) {
      paint.strokeJoin = strokeJoin;
    }
    if (strokeMiterLimit != null) {
      paint.strokeMiterLimit = strokeMiterLimit;
    }
    return SvgPathPainter._(paint);
  }

  Notifier? repaint;
  final List<Path> _paths = [];
  Path? _clipPath;
  final Paint _paint;

  void addPath(String path) => _paths.add(parseSvgPathData(path));

  void addClipPath(String path) {
    _clipPath ??= Path();
    _clipPath!.extendWithPath(parseSvgPathData(path), Offset.zero);
  }

  set color(Color color) {
    _paint.color = color;
  }

  void setLinearGradient({required double startX, required double startY, required double endX, required double endY, required List<Color> colors, List<double>? colorStops}) {
    _paint.shader = ui.Gradient.linear(Offset(startX, startY), Offset(endX, endY), colors, colorStops);
  }

  void setRadialGradient({required double centerX, required double centerY, required double radius, required List<Color> colors, List<double>? colorStops}) {
    _paint.shader = ui.Gradient.radial(Offset(centerX, centerY), radius, colors, colorStops);
  }

  void setSweepGradient({
    required double centerX,
    required double centerY,
    required List<Color> colors,
    List<double>? colorStops,
    double startAngle = 0,
    double endAngle = math.pi * 2,
  }) {
    _paint.shader = ui.Gradient.sweep(Offset(centerX, centerY), colors, colorStops, TileMode.clamp, startAngle, endAngle);
  }

  void setBlur(double sigma) {
    _paint.maskFilter = MaskFilter.blur(BlurStyle.inner, sigma);
  }

  Future<void> setImage({required String imageAssetPath, double? opacity}) async {
    final ByteData data = await rootBundle.load(imageAssetPath);
    final codec = await ui.instantiateImageCodec(Uint8List.view(data.buffer));
    final frameInfo = await codec.getNextFrame();
    _paint.color = const Color(0xFFFFFFFF).withOpacity(opacity ?? 1);
    _paint.shader = ImageShader(
      frameInfo.image,
      TileMode.repeated,
      TileMode.repeated,
      Float64List.fromList([
        1.0,
        0.0,
        0.0,
        0.0,
        0.0,
        1.0,
        0.0,
        0.0,
        0.0,
        0.0,
        1.0,
        0.0,
        0.0,
        0.0,
        0.0,
        1.0
      ]),
    );
    _notifyIsReady();
  }

  void _notifyIsReady() {
    repaint?.notify();
  }

  void draw(Canvas canvas) {
    if (_clipPath != null) {
      canvas.clipPath(_clipPath!);
    }
    _paths.forEach((element) => canvas.drawPath(element, _paint));
  }
}

class SvgPathsPainter extends CustomPainter {
  SvgPathsPainter(List<SvgPathPainter> painters, Notifier repaint)
      : _painters = painters,
        super(repaint: repaint) {
    painters.forEach((element) => element.repaint = repaint);
  }

  final List<SvgPathPainter> _painters;

  @override
  bool shouldRepaint(SvgPathsPainter oldDelegate) => true;

  @override
  void paint(Canvas canvas, Size size) {
    _painters.forEach((element) => element.draw(canvas));
  }
}

class Notifier extends Listenable {
  final List<VoidCallback> _listeners = [];

  @override
  void addListener(VoidCallback listener) {
    if (!_listeners.contains(listener)) {
      _listeners.add(listener);
    }
  }

  @override
  void removeListener(VoidCallback listener) {
    _listeners.remove(listener);
  }

  void notify() {
    _listeners.forEach((element) => element());
  }
}
