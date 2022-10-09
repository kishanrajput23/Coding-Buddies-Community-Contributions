'use strict';

// Date : 8/10/2022
// Day : Saturday

/*
	---------------------------------------------
	// part-1: Making Digital clock 
	---------------------------------------------
*/ 
const clockElm = document.querySelector('.clock');

function getCurrentTime()
{
	// we can get date form this method 
	const date = new Date();
	
	/*------------------------------------------------*/
	// we takes hours form get method
	let hours = date.getHours();
	// we takes minutes form get method
	let minutes = date.getMinutes();
	// we takes second form get method
	let seconds = date.getSeconds();
	// we just takes an am varialbe for setting am and pm
	let amOrPm = 'am';
	/*------------------------------------------------*/


	/*============================================================*/
	// we sete a condition if amOrPm > 12 then set 'pm' owtherwise 'am' and store it's value to amOrPm
	amOrPm = amOrPm > 12 ? 'pm' : amOrPm; 

	// we have seted a condition if hours > 12 then hours - 12 otherwise hours
	hours = hours > 12 ? hours - 12 : hours ; // 15 - 3
	// adding 0 with number
	let formatHours = hours < 10 ? '0' + hours : hours; // 9-09
	let formatMinutes = minutes < 10 ? '0' + minutes : minutes; // 9 - 09
	let formatSeconds = seconds < 10 ? '0' + seconds : seconds; // 9 - 09
	/*============================================================*/


	// we have taken an extra function for our code making looks like good
	shoingItemToUi(formatHours,formatMinutes,formatSeconds,amOrPm);
}

// We have called this funciton in the browser
function shoingItemToUi(hour,minute,second,amOrPm)
{
	clockElm.innerHTML = `${hour}:${minute}:${second}${amOrPm}`;
}

// setInterval() start here it will run continously after 1 second
const closeInterval = setInterval(() => 
{
	// we call the main function 
	getCurrentTime();
}, 1000);

// clearInterval(closeInterval);



