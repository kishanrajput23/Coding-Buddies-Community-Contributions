import { ContactComponent } from './contact/contact.component';
import { AboutComponent } from './about/about.component';
import { FindHospitalComponent } from './find-hospital/find-hospital.component';
import { BedBookingComponent } from './bed-booking/bed-booking.component';
import { PatientComponent } from './patient/patient.component';
import { NgModule, Component } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  { path: "", component: AboutComponent },
  { path: "hospitals", component: PatientComponent },
  { path: "hospitals/:id", component: BedBookingComponent },
  { path: "searchHospital", component: FindHospitalComponent },
  { path: "contact", component:ContactComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
