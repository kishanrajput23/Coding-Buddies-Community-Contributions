// I created gameSequence array to store the random sequence of the colours which is created by Math.randomColor
//userSequence array is used to store the sequence in which the buttons are clicked by the user
var gameSequence=[];
var userSequence=[];
var colors=["red","green","blue","yellow"];
var flag= true;
$(document).keydown(function()
{
  if(flag)
  {
    //Flag is a test variable, first it is set to true so that whenever press a key the game starts
    /* logic(), is the function where the next iteration takes place, i.e user goes to the next level , because everytime we run the logic(), a new
    random number is generated and it is added to the gameSequence*/
    logic();
    /* Here we make flag false because, once the game has started, if the user by mistake presses any key, The program should not go to the
    next interation*/
    flag= false;
  }
});
$(".btn").click(function()
{
  var clickedButton= $(this).attr("id");
  userSequence.push(clickedButton);
  makeSound(clickedButton);
  animation(clickedButton);
  working(userSequence.length-1);
});
function working(len)
{
  /* Here everytime we click on the button working() function is called and the most recent button click is checked with the corresponding element
  in the gameSequence. If both the elements match then the length is checked, only when all the elements match and the length of gameSequence and
  userSequence match, logic() runs thereby we move to the next level. If the corresponding last elements do not match at any instant then the else
  part of the code runs, ending the game, we make gameSequence empty and we set flag to true so that when the user presses the key the game starts
  again from scratch*/
  if(userSequence[len]===gameSequence[len])
  {
    if(userSequence.length===gameSequence.length)
    {
      setTimeout(function()
    {
      logic();
    },1000);
    }
  }
  else
  {
    $("h1").text("Game Over, Press Any Key to Restart");
    wrong();
    flag= true;
    gameSequence=[];

  }
}
function logic()
{
  /* Here userSequence is made empty everytime the logic() runs because, logic() runs only when the user has advanced from the previous level to the
  next level, therefore user has to enter the whole sequence again.*/
  userSequence=[];
  var no=Math.floor(Math.random()*4);
  randomColor= colors[no];
  gameSequence.push(randomColor);
  var len= gameSequence.length;
  $("h1").text("Level "+len);
  makeSound(randomColor);
  animation(randomColor);
}
function makeSound(soundColor)
{
  switch(soundColor)
  {
    case "red":
      var soundRed= new Audio("sounds/red.mp3");
      soundRed.play();
      break;
    case "blue":
      var soundBlue= new Audio("sounds/blue.mp3");
      soundBlue.play();
      break;
    case "green":
      var soundGreen= new Audio("sounds/green.mp3");
      soundGreen.play();
      break;
    case "yellow":
      var soundYellow= new Audio("sounds/yellow.mp3");
      soundYellow.play();
      break;
  }
}
function animation(animationColor)
{
  $("#"+animationColor).fadeIn(100).fadeOut(100).fadeIn(100);
}
function wrong()
{
  var soundWrong= new Audio("sounds/wrong.mp3");
  soundWrong.play();
}
