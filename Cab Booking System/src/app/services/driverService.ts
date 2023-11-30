import { HttpClient, JsonpClientBackend } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { IDriver } from 'src/driver';
import { BookingDetails } from '../bookingDetails';
import { Driver } from '../driver';
import { RideDetailsComponent } from '../ride-details/ride-details.component';
import { User } from '../user'


@Injectable({
  providedIn: 'root'
})
export class DriverService {

  constructor(private _http : HttpClient) { }

  public registerDriver(formValues: Driver):Observable<any>{
    return this._http.post<any>("http://localhost:3000/drivers",formValues);
  }
  public loginDriver(formValues: IDriver):Observable<any>{
    return this._http.get<any>("http://localhost:3000/drivers");
  }
  
  public getAvailableRides(): Observable<any>{
    return this._http.get<any>("http://localhost:3000/rides?status=Booked");
  }

  public getBookingDetails(rideId:number):Observable<BookingDetails>{
   return this._http.get<BookingDetails>("http://localhost:3000/rides/"+rideId)
  }

  public acceptRide(rideId: number, bookingDetails:BookingDetails):Observable<any>{
    var driverContext: Driver= JSON.parse(localStorage.getItem('driverContext')|| '{}')
      bookingDetails.driverName =driverContext.firstname+' '+ driverContext.lastname;
      bookingDetails.status='Accepted';
      bookingDetails.driverId=driverContext.id;
      return this._http.put<any>("http://localhost:3000/rides/"+rideId,JSON.stringify(bookingDetails), {
        headers: {'Content-Type':'application/json'}
     });
  }

  public getAllRides(){
    var driverContext: Driver= JSON.parse(localStorage.getItem('driverContext')|| '{}')
    return this._http.get<BookingDetails[]>("http://localhost:3000/rides?driverId="+driverContext.id)
  }
  public rejectRide(rideId: number):Observable<any>{
    return this._http.put<any>("http://localhost:3000/rides/"+rideId,'{"status":"Rejected"}');
}
}
