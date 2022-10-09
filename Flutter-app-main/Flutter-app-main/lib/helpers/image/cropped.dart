// import 'package:flutter/widgets.dart';

// class CroppedImage extends StatelessWidget {
//   const CroppedImage(
//     String assetUrl, {
//     @required this.width,
//     @required this.height,
//     this.scaleX = 1,
//     this.scaleY = 1,
//     this.offsetX = 0,
//     this.offsetY = 0,
//     this.color,
//   })  : assert(assetUrl != null),
//         assert(width != null),
//         assert(height != null),
//         assert(scaleX != null),
//         assert(scaleY != null),
//         assert(offsetX != null),
//         assert(offsetY != null),
//         url = assetUrl;

//   final String url;
//   final double width, height;
//   final double scaleX, scaleY;
//   final double offsetX, offsetY;
//   final Color color;

//   @override
//   Widget build(BuildContext context) {
//     return LayoutBuilder(
//         builder: (BuildContext context, BoxConstraints constraints) {
//       final int width = constraints.maxWidth ~/ scaleX;
//       final int height = constraints.maxHeight ~/ scaleY;
//       return Image(
//         image: ResizeImage(AssetImage(url),
//             width: width, height: height, allowUpscaling: true),
//         width: constraints.maxWidth,
//         height: constraints.maxHeight,
//         alignment: Alignment(
//           scaleX == 1 ? 0 : ((offsetX / (1 - scaleX)) * 2) - 1,
//           scaleY == 1 ? 0 : ((offsetY / (1 - scaleY)) * 2) - 1,
//         ),
//         fit: BoxFit.none,
//         color: color,
//         colorBlendMode: BlendMode.dstATop,
//       );
//     });
//   }
// }

import 'dart:typed_data';
import 'dart:ui' as ui;

import 'package:flutter/widgets.dart';
import 'package:flutter/services.dart';

class CroppedImage extends StatelessWidget {
  const CroppedImage(
    String assetUrl, {
    required this.width,
    required this.height,
    this.scaleX = 1,
    this.scaleY = 1,
    this.offsetX = 0,
    this.offsetY = 0,
    this.color,
  }) : url = assetUrl;

  final String url;
  final double width, height;
  final double scaleX, scaleY;
  final double offsetX, offsetY;
  final Color? color;

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (BuildContext context, BoxConstraints constraints) {
      final int width = constraints.maxWidth ~/ scaleX;
      final int height = constraints.maxHeight ~/ scaleY;
      print("WidthX: $width => ${constraints.maxWidth} => $scaleX");
      print("WidthY: $height => ${constraints.maxHeight} => $scaleY");
      return FutureBuilder<ui.Image>(
        future: resizeImage(width, height),
        builder: (BuildContext context, AsyncSnapshot<ui.Image> snapshot) {
          if (!snapshot.hasData) {
            return Container();
          }
          return CustomPaint(
            painter: ImageEditor(
              image: snapshot.data!,
              offset: Offset(-offsetX * width, -offsetY * height),
            ),
          );

          // return Image(
          //   image: ResizeImage(ExactAssetImage(url),
          //       width: width, height: height, allowUpscaling: true),
          //   width: constraints.maxWidth,
          //   height: constraints.maxHeight,
          //   alignment: Alignment(
          //     scaleX == 1 ? 0 : ((offsetX / (1 - scaleX)) * 2) - 1,
          //     scaleY == 1 ? 0 : ((offsetY / (1 - scaleY)) * 2) - 1,
          //   ),
          //   fit: BoxFit.none,
          //   color: color,
          //   colorBlendMode: BlendMode.dstATop,
          // );
        },
      );
    });
  }

  Future<ui.Image> resizeImage(int width, int height) async {
    final Uint8List m = Uint8List.view((await rootBundle.load(url)).buffer);
    final codec = await ui.instantiateImageCodec(m, targetHeight: height, targetWidth: width, allowUpscaling: true);
    final frameInfo = await codec.getNextFrame();
    print("resized image");
    return frameInfo.image;
  }
}

class ImageEditor extends CustomPainter {
  ImageEditor({
    required this.image,
    required this.offset,
  });

  ui.Image image;
  Offset offset;

  @override
  void paint(Canvas canvas, Size size) {
    canvas.drawImage(image, offset, Paint());
  }

  @override
  bool shouldRepaint(CustomPainter oldDelegate) => true;
}

// import 'dart:typed_data';
// import 'dart:ui' as ui;

// import 'package:flutter/widgets.dart';
// import 'package:flutter/services.dart';
// import 'package:image/image.dart' as image_lib;

// class CroppedImage extends StatelessWidget {
//   const CroppedImage(
//     String assetUrl, {
//     @required this.width,
//     @required this.height,
//     this.scaleX = 1,
//     this.scaleY = 1,
//     this.offsetX = 0,
//     this.offsetY = 0,
//     this.color,
//   })  : assert(assetUrl != null),
//         assert(width != null),
//         assert(height != null),
//         assert(scaleX != null),
//         assert(scaleY != null),
//         assert(offsetX != null),
//         assert(offsetY != null),
//         url = assetUrl;

//   final String url;
//   final double width, height;
//   final double scaleX, scaleY;
//   final double offsetX, offsetY;
//   final Color color;

//   @override
//   Widget build(BuildContext context) {
//     return LayoutBuilder(
//         builder: (BuildContext context, BoxConstraints constraints) {
//       final int width = constraints.maxWidth ~/ scaleX;
//       final int height = constraints.maxHeight ~/ scaleY;
//       print("WidthX: $width => ${constraints.maxWidth} => $scaleX");
//       print("WidthY: $height => ${constraints.maxHeight} => $scaleY");
//       return FutureBuilder<List<int>>(
//         future: resizeImage(width, height),
//         builder: (BuildContext context, AsyncSnapshot<List<int>> snapshot) {
//           if (!snapshot.hasData) {
//             return Container();
//           }
//           return Image.memory(
//             Uint8List.fromList(snapshot.data),
//             width: constraints.maxWidth,
//             height: constraints.maxHeight,
//             alignment: Alignment(
//               scaleX == 1 ? 0 : ((offsetX / (1 - scaleX)) * 2) - 1,
//               scaleY == 1 ? 0 : ((offsetY / (1 - scaleY)) * 2) - 1,
//             ),
//             fit: BoxFit.none,
//             color: color,
//             colorBlendMode: BlendMode.dstATop,
//           );
//           // CustomPaint(
//           //   painter: Image.memory(snapshot.data)
//           //   // ImageEditor(
//           //   //   image: snapshot.data,
//           //   //   offset: Offset(-offsetX * width, -offsetY * height),
//           //   // ),
//           // );

//           // return Image(
//           //   image: ResizeImage(ExactAssetImage(url),
//           //       width: width, height: height, allowUpscaling: true),
//           //   width: constraints.maxWidth,
//           //   height: constraints.maxHeight,
//           //   alignment: Alignment(
//           //     scaleX == 1 ? 0 : ((offsetX / (1 - scaleX)) * 2) - 1,
//           //     scaleY == 1 ? 0 : ((offsetY / (1 - scaleY)) * 2) - 1,
//           //   ),
//           //   fit: BoxFit.none,
//           //   color: color,
//           //   colorBlendMode: BlendMode.dstATop,
//           // );
//         },
//       );
//     });
//   }

//   List<int> resizeImageLib(List<int> bytes, int width, int height) {
//     image_lib.Image image1 = image_lib.decodeImage(bytes);
//     image_lib.Image thumbnail =
//         image_lib.copyResize(image1, height: height, width: width);
//     return image_lib.encodePng(thumbnail);
//   }

//   Future<List<int>> resizeImage(int width, int height) async {
//     final Uint8List m = Uint8List.view((await rootBundle.load(url)).buffer);
//     return resizeImageLib(m, width, height);
//     // final codec = await ui.instantiateImageCodec(m,
//     //     targetHeight: height, targetWidth: width, allowUpscaling: true);
//     // final frameInfo = await codec.getNextFrame();
//     // print(
//     //     "resized image: ${frameInfo.image.width} ($width), ${frameInfo.image.height} ($height)");
//     // return await _resize(frameInfo.image, width: width, height: height);
//   }

//   Future<ui.Image> _resize(ui.Image image, {int width, int height}) async {
//     final pictureRecorder = ui.PictureRecorder();
//     final canvas = Canvas(pictureRecorder);
//     canvas.drawImage(image, Offset.zero, Paint());
//     final picture = pictureRecorder.endRecording();
//     print("_resized (1)");
//     final resized = await picture.toImage(width, height); //!!! not working
//     print("_resized");
//     return resized;
//   }
// }

// class ImageEditor extends CustomPainter {
//   ImageEditor({
//     this.image,
//     this.offset,
//   });

//   ui.Image image;
//   Offset offset;

//   @override
//   void paint(Canvas canvas, Size size) {
//     canvas.drawImage(image, offset, Paint());
//   }

//   @override
//   bool shouldRepaint(CustomPainter oldDelegate) => true;
// }
