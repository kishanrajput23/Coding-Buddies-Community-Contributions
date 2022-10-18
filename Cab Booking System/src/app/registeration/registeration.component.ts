import { Component, OnInit } from '@angular/core';
import { NgForm } from '@angular/forms';
import { Router } from '@angular/router';
import { UserService } from '../services/userService';
import { User } from '../user';

@Component({
  selector: 'app-registeration',
  templateUrl: './registeration.component.html',
  styleUrls: ['./registeration.component.css']
})
export class RegisterationComponent implements OnInit {

  user = new User();
  msg = "";

  constructor(private _service: UserService, private _router: Router) { }

  ngOnInit() {

  }

  registerUser(formvalues: User) {

    this._service.registeerUser(formvalues).subscribe(

      data => {
        alert('Registered Successfull..!');
        this._router.navigate(['/login']);
      }, error => {
        console.log("Srry Check Ur details Again");
        alert("Registration Failed.........!");
      }

    )

  }
}
