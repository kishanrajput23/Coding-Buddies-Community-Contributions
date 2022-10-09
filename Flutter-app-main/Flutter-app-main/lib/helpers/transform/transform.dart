import 'package:flutter/widgets.dart';

class TransformHelper {
  static Transform rotate({double? a, double? b, double? c, double? d, Widget? child}) {
    return Transform(
      transform: Matrix4(a ?? 1, c ?? 0, 0, 0, b ?? 0, d ?? 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1),
      alignment: Alignment.topLeft,
      child: child,
    );
  }

  static Transform scale({double? x, double? y, double? z, Widget? child}) {
    return Transform(
      transform: Matrix4(x ?? 1, 0, 0, 0, 0, y ?? 1, 0, 0, 0, 0, z ?? 1, 0, 0, 0, 0, 1),
      alignment: Alignment.topLeft,
      child: child,
    );
  }

  static Transform translate({double? x, double? y, double? z, Widget? child}) {
    return Transform(
      transform: Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x ?? 0, y ?? 0, z ?? 0, 1),
      alignment: Alignment.topLeft,
      child: child,
    );
  }

  static Transform translateAndScale({
    double? translateX,
    double? translateY,
    double? translateZ,
    double? scaleX,
    double? scaleY,
    double? scaleZ,
    Widget? child,
  }) {
    return Transform(
      transform: Matrix4(scaleX ?? 1, 0, 0, 0, 0, scaleY ?? 1, 0, 0, 0, 0, scaleZ ?? 1, 0, translateX ?? 0, translateY ?? 0, translateZ ?? 0, 1),
      alignment: Alignment.topLeft,
      child: child,
    );
  }
}
