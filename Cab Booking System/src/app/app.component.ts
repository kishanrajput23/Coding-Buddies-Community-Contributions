import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Cab booking system';
  userLoggedIn: Boolean= false;
  ngOnInit() {
    
  }

}
