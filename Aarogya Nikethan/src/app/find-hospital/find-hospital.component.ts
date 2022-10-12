import { PatientService } from './../patient/patient.service';
import { Component, OnInit } from '@angular/core';
import { Hospital } from '../interfaces/hospital';

@Component({
  selector: 'app-find-hospital',
  templateUrl: './find-hospital.component.html',
  styleUrls: ['./find-hospital.component.css']
})
export class FindHospitalComponent implements OnInit {

  city:string = "";
  hospitals: any = [];
  // hospitals:Array<Hospital> = new Array<Hospital>();

  constructor( private service: PatientService) { }

  ngOnInit(): void {
  }

  public fetchHospitals(): void {
    console.log(this.city);
    this.service.getHospitalByName(this.city).subscribe((list) => {
      this.hospitals=list;
    })
  }

}
