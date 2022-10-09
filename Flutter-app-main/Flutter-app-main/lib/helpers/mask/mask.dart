import 'package:flutter/material.dart';
import 'package:path_drawing/path_drawing.dart';

class Mask extends StatelessWidget {
  const Mask(this.clipPath, {this.child});

  factory Mask.fromSVGPath(String svgPath, {Widget? child, Offset? offset}) {
    Path path = parseSvgPathData(svgPath);
    if (offset != null) {
      path = path.shift(offset);
    }
    return Mask(path, child: child);
  }
  final Path clipPath;

  final Widget? child;

  @override
  Widget build(BuildContext context) => ClipPath(
        clipper: PathClipper(clipPath),
        child: child,
      );
}

class PathClipper extends CustomClipper<Path> {
  const PathClipper(this.path);

  final Path path;

  @override
  Path getClip(Size size) {
    return path;
  }

  @override
  bool shouldReclip(CustomClipper<Path> oldClipper) => false;
}
