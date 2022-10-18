import { Component, OnInit } from '@angular/core';
import {Router} from '@angular/router'
@Component({
  selector: 'app-navbar',
  templateUrl: './navbar.component.html',
  styleUrls: ['./navbar.component.css']
})
export class NavbarComponent implements OnInit {

  public sessionValid:boolean=false;
  constructor(private _roter:Router) { }

  ngOnInit(): void {
    if(localStorage.getItem('userContext') || localStorage.getItem('driverContext')){
      this.sessionValid=true;
    }else{
      this._roter.navigate(['/welcome']);
    }
  }

  logout(){
    localStorage.removeItem('userContext');
    localStorage.removeItem('driverContext');
    this.sessionValid=false;
    this._roter.navigate(['/welcome']);

  }
}
