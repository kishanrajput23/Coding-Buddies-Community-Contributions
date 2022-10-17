import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { LoginComponent } from './login/login.component';
import { RegisterationComponent } from './registeration/registeration.component';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';
import { LoginsuccessComponent } from './login/loginsuccess/loginsuccess.component';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import { UserComponent } from './user/user.component';
import { DriverComponent } from './driver/driver.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { HomeComponent } from './home/home.component';
import { CabBookingDetailsComponent } from './cab-booking-details/cab-booking-details.component';
import { WelcomeComponent } from './welcome/welcome.component';
import { RideDetailsComponent } from './ride-details/ride-details.component';
import { UserRidesComponent } from './user-rides/user-rides.component';
import { DriverridesComponent } from './driverrides/driverrides.component';
import { DriverhomeComponent } from './driverhome/driverhome.component';
import { DriverregisterComponent } from './driverregister/driverregister.component';
import { NavbarComponent } from './navbar/navbar.component';




@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    RegisterationComponent,
    LoginsuccessComponent,
    UserComponent,
    DriverComponent,
    PageNotFoundComponent,
    HomeComponent,
    CabBookingDetailsComponent,
    WelcomeComponent,
    RideDetailsComponent,
    UserRidesComponent,
    DriverridesComponent,
    DriverhomeComponent,
    DriverregisterComponent,
    NavbarComponent,
  
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    AppRoutingModule,
     BrowserAnimationsModule,

  ],
  providers: [],
  bootstrap: [AppComponent,]
})
export class AppModule { }
