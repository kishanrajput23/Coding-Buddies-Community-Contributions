import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Output, EventEmitter } from '@angular/core';
import { UserService } from '../services/userService';
import { User } from '../user';
import { RegisterationService } from '../registeration.service';
import { BookingDetails } from '../bookingDetails';

@Component({
  selector: 'app-user',
  templateUrl: './user.component.html',
  styleUrls: ['./user.component.css']
})
export class UserComponent implements OnInit {

  
  msg = "";
  validDetails=false;
  fare: number=0;
  carType: string="";
  constructor(private _service :  UserService, private _router: Router) { }

  booking(formvalues:any){
    let userId= localStorage.getItem('loggedInUser');
    let driverId='';
    if(userId==undefined)
      userId=''
    const rideDetails: BookingDetails = new BookingDetails(
      formvalues.source, formvalues.destination,this.fare, this.carType, userId,driverId,'Booked'
    );
    this._service.bookRide(rideDetails).subscribe(
      _data => { 
        alert("Cab booking successful");
        this._router.navigate(['/rideDetails/'+_data.id]);
      },
        
      error => { 
        console.log("Exception occurred");
        this.msg = error.error;
      }
    )


  }
 

  ngOnInit() {
   
  }
  dropdownChange(){
    this.fare= Math.floor(Math.random() * (200 - 100 + 1)) + 100;
  }

  displayUserRides(){
    this._router.navigate(['/userRides']);
  }

}
