import {Component, EventEmitter, OnInit, Output} from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-loginsuccess',
  templateUrl: 'loginsuccess.component.html',
  styleUrls: ['loginsuccess.component.css']
})
export class LoginsuccessComponent implements OnInit {

  constructor(private router:Router) { }

  ngOnInit() {
  }
   
  onSelect(){
      this.router.navigate(['/home']);
  }
  
}
