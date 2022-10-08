1) Facebook Login & Sing-up Page Code

<!DOCTYPE html ?
<html lang="en">
<head>
 <title> facebook login or sign up </title>
 <link rel="stylesheet" type="text/css" href="style.css">
 </head>
<body>
 <nav class="navbar">
 <img class="logo" src="fb.png">
 <form class="login_form" action="data4.php" method="post">
 <div class="font">Email or Phone</div>
 <input type="text" for ="name" name="email">
 </div>
 <div class="password">
 <div class="font">Password</div>
 <input type="password" for ="password" name="password">
</div>
<button class="login_btn">Login</button>
</form>
</nav>
<br>
<section>
<div class="singup_body">
 <p class="acc_crt">Create An Account For Php Task Facebook..</p>
 <p class="free_hint">Its Free And Always Will Be.</p>
 <form class="signup_form" action="data5.php" method="post">
 <div>
 <input class="firstname" type="text" for ="firstname" name="firstname" 
placeholder="First name">
 <input class="lastname" type="text" for="lastname" name="lastname" 
placeholder="Last name">
 <input class="email1" type="text" for="email1" name="email1" 
placeholder="Mobile number or Email">
 <input class="password1" type="password" for="password1" 
name="password1" placeholder="Password">
 <input class="password2" type="password" for="password2" 
name="password2" placeholder="Confirm Password">
 
 </div>
 
 <p class="birthday">Birthday</p>
 <div class="month">
 <select class="month" name="month">
 
<option>Month</option><option>jan</option><option>feb</option><option>
march</option>
 
<option>april</option><option>may</option><option>june</option><option>
july</option>
 
<option>aug</option><option>sept</option><option>oct</option><option>n
ov</option>
 <option>dec</option> 
 </select>
 
 <select class="day" name="day">
 
<option>day</option><option>1</option><option>2</option><option>3</opt
ion>
 
<option>4</option><option>5</option><option>6</option><option>7</optio
n>
 
<option>8</option><option>9</option><option>10</option><option>11</opt
ion>
 
<option>12</option><option>13</option><option>14</option><option>15</
option>
 
<option>16</option><option>17</option><option>18</option><option>19</
option>
 
<option>20</option><option>21</option><option>22</option><option>23</
option>
 
<option>24</option><option>25</option><option>26</option><option>27</
option>
 
<option>28</option><option>29</option><option>30</option><option>31</
option>
 </select>
 
 <select class="year" name="year">
 
<option>Year</option><option>1997</option><option>1998</option><option
>1999</option>
 
<option>2000</option><option>2001</option><option>2002</option><optio
n>2003</option>
 
<option>2004</option><option>2005</option><option>2006</option><optio
n>2007</option>
 <option>2008</option>
 </select>
 <br>
 <p class="birth_hint"><a href="#">Why Do I Need To Provide My 
Birthdate</a></p>
 </div>
 <input type="radio" name="gender" value="male">
 <input type="radio" name="gender" value="female">
 
 <p class ="font">Male</p>
 <p class="font font2">Female</p>
 <p class="agreement">By Clicking Signup, You Agree To lavish Trail Php 
Page
 <a href="#">Terms, Data Policy And
 Cookies Policy.</a> <br>
 You May Receive SMS Notifiction From Us And Can OptOut Any Time 
!!</p>
 <input type = "Submit"/>
 <div class="logo_body">
 <img class="logobody" src="fbbdy.png">
 <p class="like_font font1">Thanks For Lavish Side !! </p>
 <p class="like_font">Lavish Hope To Meet You Again Soon.</p>
</div>
 <style>
.btn {
 border: none;
 color: white;
 padding: 14px 28px;
 font-size: 16px;
 cursor: pointer;
}
.success {background-color: #04AA6D;} /* Green */
.success:hover {background-color: #46a049;}
.info {background-color: #2196F3;} /* Blue */
.info:hover {background: #0b7dda;}
.warning {background-color: #ff9800;} /* Orange */
.warning:hover {background: #e68a00;}
.danger {background-color: #f44336;} /* Red */ 
.danger:hover {background: #da190b;}
.default {background-color: #e7e7e7; color: black;} /* Gray */ 
.default:hover {background: #ddd;}
</style>
<h1>Alert Buttons</h1>
<button class="btn success">Success</button>
<button class="btn info">Info</button>
<button class="btn warning">Warning</button>
<button class="btn danger">Danger</button>
<button class="btn default">Default</button>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/fontawesome/4.7.0/css/font-awesome.min.css">
<style>
.fa {
 padding: 20px;
 font-size: 30px;
 width: 50px;
 text-align: center;
 text-decoration: none;
 margin: 5px 2px;
}
.fa-facebook {
 background: #3B5998;
 color: white;
}
.fa-twitter {
 background: #55ACEE;
 color: white;
}
.fa-google {
 background: #dd4b39;
 color: white;
}
.fa-linkedin {
 background: #007bb5;
 color: white;
}
.fa-youtube {
 background: #bb0000;
 color: white;
}
.fa-instagram {
 background: #125688;
 color: white;
}
.fa-pinterest {
 background: #cb2027;
 color: white;
}
.fa-snapchat-ghost {
 background: #fffc00;
 color: white;
 text-shadow: -1px 0 black, 0 1px black, 1px 0 black, 0 -1px black;
}
.fa-skype {
 background: #00aff0;
 color: white;
}
.fa-android {
 background: #a4c639;
 color: white;
}
.fa-yahoo {
 background: #430297;
 color: white;
}
</style>
</head>
<body>
<h2>Style Social Media Buttons</h2>
<!-- Add font awesome icons -->
<a href="#" class="fa fa-facebook"></a>
<a href="#" class="fa fa-twitter"></a>
<a href="#" class="fa fa-google"></a>
<a href="#" class="fa fa-linkedin"></a>
<a href="#" class="fa fa-youtube"></a>
<a href="#" class="fa fa-instagram"></a>
<a href="#" class="fa fa-pinterest"></a>
<a href="#" class="fa fa-snapchat-ghost"></a>
<a href="#" class="fa fa-skype"></a>
<a href="#" class="fa fa-yahoo"></a>
 
</style>
</form>
</div>
</section>
</body>
</html>


2) Data Page For CSS Design of Page:-

*{
 margin: 0;
 padding: 0;
}
.navbar{
 height: 80px;
 width: 100%;
 background: linear-gradient(#48649F, #3B5998, #3B5998);
 border-bottom: 1px solid #253a69;
}
.logo{
 position: absolute;
 height: 63px;
 width: 190px;
 left: 13%;
 padding-top: 15px;
}
.login_form{
 display: flex;
 position: absolute;
 font-family: verdana;
 left: 58%;
 top: 15px;
}
.login_form .email,
.login_form .password{
 padding-left: 15px;
}
.login_form .email .font,
.login_form .password .font{
 font-size: 13px;
 padding-bottom: 4px;
 color: white;
}
.login_form .email input,
.login_form .password input{
 height: 23px;
 width: 150px;
 padding-left: 15px;
 border: 1px solid black;
 outline: none;
}
.login_form button{
 height: 24px;
 width: 50px;
 font-weight: 600;
 margin-left: 15px;
 margin-top: 20px;
 border-radius: 2px;
 outline: none;
 color: white;
 cursor: pointer;
 background: #2d5bba;
 border: 1px solid #224285;
}
.login_form button:hover{
 background: #3B5998;
}
section{
 height: 2000px;
 width: 100%;
 top: 80px;
 background: linear-gradient(#FDFDFE, #EFF1F6, #E3E6F0, #E1E5F0, 
#D6DBEA);
 font-family: verdana;
}
.signup_body{
 font-family: arial;
 position: absolute;
 left: 57%; 
}
.signup_body .acc_crt{
 font-size: 40px;
 margin: 25px 0;
}
.signup_body .free_hint{
 margin: -20px 5px;
 font-size: 18px;
}
.signup_body .signup_form input{
 margin-top: 50px;
 height: 138px;
 width: 190px;
 padding-left: 10px;
 font-size: 18px;
 border: 1px solid silver;
 border-radius: 4px;
}
.signup_body .signup_form .lastname{
 margin-left: 15px;
}
.signup_body .signup_form .email,
.signup_body .signup_form .password,
.signup_body .signup_form .password2{

 margin-top: 20px;
 width: 410px;
}
.signup_body .signup_form .birthday{
 margin-top: 15px;
 font-size: 20px;
 font-weight: bold;
 color: grey;
}
.signup_body .signup_form .birth_date{
 margin-top: 5px;
}
.signup_body .signup_form .month,
.signup_body .signup_form .day,
.signup_body .signup_form .year{
 height: 28px;
}
.signup_body .signup_form .day,
.signup_body .signup_form .year{
 margin-left: -5px;
}
.signup_body .signup_form .brth_hint{
 font-size: 11px;
 padding-left: 170px;
 margin-top: -28px;
 width: 150px;
}
.signup_body .signup_form a{
 text-decoration: none;
}
.signup_body .signup_form a:hover{
 text-decoration: underline;
}
.signup_body .signup_form input[type="radio"]{
 height: 15px;
 margin-left: -50px;
 margin-top: 30px;
}
.signup_body .signup_form input[value="female"]{
 margin-left: -100px;
}
.signup_body .signup_form .font{
 margin-left: 57px;
 margin-top: -17px;
}
.signup_body .signup_form .font2{
 margin-left: 150px;
}
.signup_body .signup_form .agreement{
 margin-top: 15px;
 font-size: 12px;
 width: 350px;
 color: grey;
}
.signup_body .signup_form .signup{
 margin-top: 20px;
 height: 38px;
 width: 170px;
 color: white;
 font-size: 20px;
 font-weight: 600;
 border: 1px solid #006117;
 border-radius: 3px;
 cursor: pointer;
 outline: none;
 background: linear-gradient(#6fad5a, #66a150, #60974C);
}
.signup_body .signup_form .signup:hover{
 background: linear-gradient(#74b85e, #598B45);
}
.logo_body{
 position: absolute;
 left: 75%;
 top: 25%;
}
.logo_body .like_font{
 font-family: arial;
 font-size: 25px;
 margin-left: -30px;
}
.logo_body .font1{
 color: #083987;
 margin-left: 20px; 
 margin-bottom: 5px;
}


3) Code For Post Method of Login Page :-

<!DOCTYPE html ?
<html lang="en">
 <head>
 <meta charset="UTF=8">
 <meta http-equiv="X-UA-Compatible" content="IE-edge">
 <meta name="viewport" content="width-device-width, initialscale=1.0">
 <title> Fb Php Form </title>
</head>
<body>
<body style="background-color:powderblue;">
<?php 
$e= $_POST['email'];
$p= $_POST['password'];
$fnm= $_POST['firstname'];
$lnm= $_POST['lastname'];
$e1= $_POST['email1'];
$p1= $_POST['password1'];
$p2= $_POST['password2'];
echo $e;
echo "<br>";
echo $p;
echo "<br>";
?>
</body>
</html>


4) Code For Post Method of Sign-Up Page:-

<!DOCTYPE html ?
<html lang="en">
 <head>
 <meta charset="UTF=8">
 <meta http-equiv="X-UA-Compatible" content="IE-edge">
 <meta name="viewport" content="width-device-width, initialscale=1.0">
 <title> Fb Php Form </title>
</head>
<body>
<body style="background-color:powderblue;">
<?php 
$fnm= $_POST['firstname'];
$lnm= $_POST['lastname'];
$e1= $_POST['email1'];
$p1= $_POST['password1'];
$p2= $_POST['password2'];
$mon= $_POST['month'];
$day= $_POST['day'];
$yr= $_POST['year'];
$gen= $_POST['gender'];
echo $fnm;
echo "<br>";
echo $lnm;
echo "<br>";
echo $e1;
echo "<br>";
echo $p1;
echo "<br>";
echo $p2;
echo "<br>";
echo $yr;
echo "<br>";
echo $mon;
echo "<br>";
echo $day;
echo "<br>";
echo $gen;
?>
</body>
</html>

Output:-
![Screenshot (31)](https://user-images.githubusercontent.com/109017996/194722234-dbb54858-99f2-46b4-b44a-430b0026f951.png)


------------------------------------------------------------------------(CB)-------------------------------------------------------------------------
