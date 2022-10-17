import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import {Driver} from '../driver';
import {DriverService} from '../services/driverService'

@Component({
  selector: 'app-driverregister',
  templateUrl: './driverregister.component.html',
  styleUrls: ['./driverregister.component.css']
})
export class DriverregisterComponent implements OnInit {

  constructor(private _service: DriverService, private _router: Router) { }

  ngOnInit(): void {
  }
  registerDriver(formvalues: Driver) {

    this._service.registerDriver(formvalues).subscribe(

      data => {
        alert('Registered Successfull..!');
        this._router.navigate(['/driver']);
      }, error => {
        console.log("Srry Check Ur details Again");
        alert("Registration Failed.........!");
      }

    )
  }

}
