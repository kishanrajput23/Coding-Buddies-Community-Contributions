import { Component, OnInit } from '@angular/core';
import { BookingDetails } from '../bookingDetails';
import { User } from '../user';
import { UserService } from '../user.service';

@Component({
  selector: 'app-cab-booking-details',
  templateUrl: './cab-booking-details.component.html',
  styleUrls: ['./cab-booking-details.component.css']
})
export class CabBookingDetailsComponent implements OnInit {

  userDetails:BookingDetails[]=[];
  constructor(private _service:UserService) { }

  ngOnInit(): void {

    this._service.getBookingDetails().subscribe(
      data=>{this.userDetails=data},
      error=>{console.log("error occured!")}
    );
  }

}
