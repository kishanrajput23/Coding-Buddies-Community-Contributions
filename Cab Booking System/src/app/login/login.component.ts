import { Component, OnInit } from '@angular/core';
import { NgForm } from '@angular/forms';
import { Router } from '@angular/router';
import { allowedNodeEnvironmentFlags } from 'process';
import { UserService } from '../services/userService';
import { User } from '../user';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  message: string="";

  constructor(private _service : UserService, private _router : Router) { }

  ngOnInit() {
    if(localStorage.getItem('loggedInUser')!=undefined){
      //this._router.navigate(['/user']);
    }
  }

loginUser(formvalues: User){​​​​

    (this._service.loginUsers(formvalues)).subscribe(

      (data: any) => {
        let userFound: boolean= false;
        data.forEach(function (u: User) {
          if(formvalues.username== u.username && formvalues.password==u.password){
           userFound=true;
           localStorage.setItem('userContext',JSON.stringify(u));
          }  
        });
        if(userFound){
          this._router.navigate(['/user']);
          return;
        }
        else{
          alert('Invalid Credentials');
        }

  }​​​​,(error: any)=>{​​​​
      this._router.navigate(['']);
  }​​​​);

  }​​​​ 

}


