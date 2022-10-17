import { Component, Input, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { BookingDetails } from '../bookingDetails';
import {UserService}  from '../services/userService'
@Component({
  selector: 'app-ride-details',
  templateUrl: './ride-details.component.html',
  styleUrls: ['./ride-details.component.css']
})
export class RideDetailsComponent implements OnInit {

  constructor(private _router: Router, private _service :UserService) { }
  rideDetails: any;
  isDriver: boolean= false;
  ngOnInit(): void {
    this.loadRideDetails();
  }

  loadRideDetails(){
    var riddeId=this._router.url.split('/').pop();
    this._service.getRideDetails(Number(riddeId)).subscribe(
        data=>{
          this.rideDetails=data;
        }
    );
    if(localStorage.getItem('driverContext')!=null){
      this.isDriver= true;
    }else{
      this.isDriver=false;
    }
  }


  cancelRide(){
    var riddeId=this._router.url.split('/').pop();
    this._service.cancelRide(Number(riddeId)).subscribe();
    this._router.navigate(['/user']);
  }

}
