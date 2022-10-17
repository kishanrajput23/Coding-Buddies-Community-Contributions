 function bmi(){
           var h = document.getElementById('height').value;
           var w = document.getElementById('weight').value;
           var bmi = w / (h/100*h/100);
           var total = bmi.toFixed(2);
           document.getElementById('result').innerHTML = "Your BMI is "+ total
         }
 window.onload = function () {
            var images = ['BMI.jpg', 'BMI2.jpg', 'BMI3.jpg','BMI3.jpg', 'BMI5.jpg'];
            var image = images[Math.floor(Math.random() * images.length)];
            document.getElementsByTagName('body')[0].style.backgroundImage = "url('" + image + "')";
            document.getElementsByTagName('body')[0].style.backgroundRepeat = "no-repeat";
            document.getElementsByTagName('body')[0].style.backgroundSize = "cover";
        }
		alert("This page shows random background images");