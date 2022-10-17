import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { BookingDetails } from '../bookingDetails';
import { DriverService } from '../services/driverService'
@Component({
  selector: 'app-driverhome',
  templateUrl: './driverhome.component.html',
  styleUrls: ['./driverhome.component.css']
})
export class DriverhomeComponent implements OnInit {

  public availableRides:Array<BookingDetails>=[];
  public bookingDetails: any;
  constructor(private _router:Router, private serivce: DriverService) { }
  

  ngOnInit(): void {
    this.loadAvailableRides();
  }

  loadAvailableRides(){
    this.serivce.getAvailableRides().subscribe(
      _data => { 
        this.availableRides= _data;
      },
        
      error => { 
        console.log("Exception occurred");
      }
    );



  }
  async acceptRide(event:any){
    var target = event.target || event.srcElement || event.currentTarget;
    var idAttr = target.id;
    
    await this.serivce.getBookingDetails(idAttr).subscribe(
      data=>{
         this.bookingDetails=data;
      }
    )
    await this.serivce.acceptRide(idAttr, this.bookingDetails).subscribe(
      _data => { 
        alert('Ride Accepted');
        this._router.navigate(['/rideDetails/'+idAttr])
      }, 
      error => { 
        console.log("Exception occurred");
      }
    ); 
  }
  rejectRide(event:any){
    var target = event.target || event.srcElement || event.currentTarget;
    var idAttr = target.id;
    this.serivce.rejectRide(idAttr).subscribe(
      _data => { 
        alert('Ride Rejected');
        this.ngOnInit();
      }, 
      error => { 
        console.log("Exception occurred");
      }
    ); 
  }
  showDriverRides(){
    this._router.navigate(['/driverrides']);
  }
}
