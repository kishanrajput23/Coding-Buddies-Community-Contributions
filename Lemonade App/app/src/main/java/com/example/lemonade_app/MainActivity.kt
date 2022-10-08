package com.example.lemonade_app

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val image1: ImageView = findViewById(R.id.imageView)
        image1.setImageResource(R.drawable.lemon_tree)
        val text1: TextView = findViewById(R.id.textView)

        val images= arrayListOf<Int>(R.drawable.lemon_tree,R.drawable.lemon_squeeze,R.drawable.lemon_drink,R.drawable.lemon_restart)
        val texts= arrayListOf<String>("Click to select a lemon","Click to juice a lemon","Click to drink your lemonade","Click to start again")

        var i =0

        image1.setOnClickListener {
            if (i < 3) {
                i++
                image1.setImageResource(images[i])
                text1.setText(texts[i])
            }
            else {
                i = 0
                image1.setImageResource(images[i])
                text1.setText(texts[i])
            }
        }

//            if(i==1)
//                text1.text = "Click to juice a lemon"
//            if(i==2)
//                text1.text = "Click to drink your lemonade"
//            if(i==3)
//                text1.text = "Click to start again"

//        val image2: ImageView = findViewById(R.id.imageView)
//
//
//        val image3: ImageView = findViewById(R.id.imageView)
//
//
//        val image4: ImageView = findViewById(R.id.imageView)



//        var i = 0;

//        if(i==0) {
//            image1.setOnClickListener {
//                image1.setImageResource(R.drawable.lemon_squeeze)
//
//            }
//            i++
//        }

//        if(i==1) {
//            image1.setOnClickListener {
//                image1.setImageResource(R.drawable.lemon_drink)
//                text1.text = "Click to drink your lemonade"
//            }
//            i++
//        }

//        image1.setOnClickListener{
//            image1.setImageResource(R.drawable.lemon_restart)
//            text1.text = "Click to start again"
//        }

//        image1.setOnClickListener{
//            image1.setImageResource(R.drawable.lemon_tree)
//            text1.text = "Click to select a lemon!"
//        }

    }
}
