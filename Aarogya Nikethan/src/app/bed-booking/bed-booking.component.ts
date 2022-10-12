import { BedBookingService } from './bed-booking.service';
import { Booking } from './../interfaces/booking';
import { PatientService } from './../patient/patient.service';
import { Component, Input, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';

@Component({
  selector: 'app-bed-booking',
  templateUrl: './bed-booking.component.html',
  styleUrls: ['./bed-booking.component.css']
})
export class BedBookingComponent implements OnInit {

  hospitals: any = [];
  
  constructor(
    private activatedRoute: ActivatedRoute,
    private route: Router,
    private service: PatientService,
    private bookingService: BedBookingService
  ) { }

  ngOnInit(): void {
    this.activatedRoute.params.subscribe(params => {
      this.service.getById(params.id).subscribe(data => {
        this.hospitals = data;
        console.log(data);
      })
    })
  }

  bookBed(formObj: Booking) {
    console.log(formObj);
    this.bookingService.bookAppointment(formObj).subscribe(() => {
      this.hospitals.bedsAvailable = this.hospitals.bedsAvailable-1;
      console.log(this.hospitals.bedsAvailable);
      alert("Your Appointment is booked at hospital: "+ formObj.hospitalName);
      this.route.navigate(['/hospitals']);
    });
  }

}
