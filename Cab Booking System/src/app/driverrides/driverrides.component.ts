import { Component, OnInit } from '@angular/core';
import { BookingDetails } from '../bookingDetails';
import { Router } from '@angular/router';
import { DriverService } from '../services/driverService';
@Component({
  selector: 'app-driverrides',
  templateUrl: './driverrides.component.html',
  styleUrls: ['./driverrides.component.css']
})
export class DriverridesComponent implements OnInit {


  driverRides: BookingDetails[]= [];

  constructor(private service: DriverService) { }
  


  ngOnInit(): void {
    this.loadDriverRides();
  }
  loadDriverRides(){
    this.service.getAllRides().subscribe(
      data=> {
        this.driverRides=data;
      }
    )
  }

}
