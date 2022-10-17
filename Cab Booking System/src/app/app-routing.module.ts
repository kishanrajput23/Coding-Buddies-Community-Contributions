import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { LoginComponent } from './login/login.component';
import { LoginsuccessComponent } from './login/loginsuccess/loginsuccess.component';
import { RegisterationComponent } from './registeration/registeration.component';
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
import {DriverregisterComponent} from './driverregister/driverregister.component';


const routes: Routes = [

 
  {path:'login', component:LoginComponent},
  {path:'registeration', component:RegisterationComponent},
  {path:'loginsuccess', component:LoginsuccessComponent},
  {path:'user',component:UserComponent},
  {path:'driver',component:DriverComponent},
  {path:'cabDetails',component:CabBookingDetailsComponent},
  {path:'welcome',component:WelcomeComponent},
  {path:'rideDetails/:id', component:RideDetailsComponent},
  {path:'driverrides', component:DriverridesComponent},
  {path:'userRides',component:UserRidesComponent},
  {path:'driverhome',component:DriverhomeComponent},
  {path:'driverRegister',component:DriverregisterComponent},
  {path:'', redirectTo:'/welcome',pathMatch:'full'},
  {path:'**',component:PageNotFoundComponent},
  


];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
