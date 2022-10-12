import { PatientService } from './patient.service';
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-patient',
  templateUrl: './patient.component.html',
  styleUrls: ['./patient.component.css']
})
export class PatientComponent implements OnInit {

  hospitals:any = [];

  constructor(private service: PatientService) { }

  ngOnInit(): void {
    this.loadHospitals()
  }

  loadHospitals() {
    return this.service.sendGetRequest().subscribe((data : {}) => {
      console.log(data);
      this.hospitals = data;
    })
  }

}
