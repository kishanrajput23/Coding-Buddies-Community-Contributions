import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Output, EventEmitter } from '@angular/core';
import {  User } from '../user'
import { IDriver } from 'src/driver';
import { DriverService } from '../services/driverService';
import { Driver } from '../driver';


@Component({
  selector: 'app-user',
  templateUrl: './driver.component.html',
  styleUrls: ['./driver.component.css']
})
export class DriverComponent implements OnInit {

  constructor(private service:DriverService,private _router:Router) { }


  ngOnInit(): void {
  }

  submitDriver(formvalues:IDriver){
    this.service.loginDriver(formvalues).subscribe(
      (data: any) => {
        let userFound: boolean= false;
        data.forEach(function (u: Driver) {
          if(formvalues.username== u.username && formvalues.password==u.password){
           userFound=true;
           localStorage.setItem('loggedInDriver',u.id);
           localStorage.setItem('driverContext',JSON.stringify(u));
          }  
        });
        if(userFound){
          this._router.navigate(['/driverhome']);
          return;
        }
        else{
          alert('Invalid Credentials');
        }
    
    });
  }
  


}

