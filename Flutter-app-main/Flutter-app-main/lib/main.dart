import 'package:flutter/material.dart';
import 'package:flutterapp/medicalappapp/generatednextwidget/GeneratedNEXTWidget.dart';
import 'package:flutterapp/medicalappapp/generatedandroidlarge1widget/GeneratedAndroidLarge1Widget.dart';
import 'package:flutterapp/medicalappapp/generatedandroidlarge2widget/GeneratedAndroidLarge2Widget.dart';
import 'package:flutterapp/medicalappapp/generatedandroidlarge3widget/GeneratedAndroidLarge3Widget.dart';
import 'package:flutterapp/medicalappapp/generatedandroidlarge4widget/GeneratedAndroidLarge4Widget.dart';

void main() {
  runApp(MedicalappApp());
}

class MedicalappApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      initialRoute: '/GeneratedAndroidLarge1Widget',
      routes: {
        '/GeneratedNEXTWidget': (context) => GeneratedNEXTWidget(),
        '/GeneratedAndroidLarge1Widget': (context) =>
            GeneratedAndroidLarge1Widget(),
        '/GeneratedAndroidLarge2Widget': (context) =>
            GeneratedAndroidLarge2Widget(),
        '/GeneratedAndroidLarge3Widget': (context) =>
            GeneratedAndroidLarge3Widget(),
        '/GeneratedAndroidLarge4Widget': (context) =>
            GeneratedAndroidLarge4Widget(),
      },
    );
  }
}
