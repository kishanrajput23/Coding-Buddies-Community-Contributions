function validation(){
  var username=document.myform.username.value;
  if (username==""){
    document.getElementById("err1").innerHTML="*Please enter your name";
    return false;
  }
  else{
  document.getElementById("err1").innerHTML="";
  }

  var phonenum=document.myform.phone.value;
  if (phonenum==""){
    document.getElementById("err2").innerHTML="*Please enter your Phone Number";
    return false;
  }
  else if (phonenum.length !=10||isNaN(phonenum)){
    document.getElementById("err2").innerHTML="*Invalid Phone number";
    return false;
  } 
  else{
    document.getElementById("err2").innerHTML="";
  }

  var email=document.myform.email.value;
  var email1=/^([a-zA-Z0-9-_\.]+)@([a-zA-Z0-9]+)\.([a-zA-Z]{2,10})(\.[a-zA-Z]{2,8})?$/;
  if (email==""){
    document.getElementById("err3").innerHTML="*Please enter your email";
    return false;
  }
  else if (!email1.test(email)){
    document.getElementById("err3").innerHTML="*Invalid email address";
    return false;
  }
  else{
  document.getElementById("err3").innerHTML="";
  }
  
  var address=document.myform.address.value;
  if (address==""){
    document.getElementById("err4").innerHTML="*Please enter your address";
    return false;
  }
  else{
    document.getElementById("err4").innerHTML="";
  }
  
  if(username !==""&&phonenum !==""&&phonenum.length ==10&&email !==""&&address !==""&&email1.test(email)&&!isNaN(phonenum)){
    alert('Registration successfull,'+' '+'Thank you, Mr./Mrs.'+' '+document.getElementById("username").value+' '+', We will contact you soon.');
  }

}