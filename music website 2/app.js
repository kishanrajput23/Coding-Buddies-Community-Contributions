let mysong=document.getElementById("mysong");
let icon=document.getElementById("icon");
icon.addEventListener("click",function(){
    if(mysong.paused){
        mysong.play();
        icon.src="pause.png";
    }
    else{
        mysong.pause();
        icon.src="play.png";
    }
})
