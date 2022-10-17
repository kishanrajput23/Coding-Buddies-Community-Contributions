import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { IDriver } from 'src/driver';
import { BookingDetails } from './bookingDetails';
import { of } from 'rxjs';
import { User } from './user'

@Injectable({
  providedIn: 'root'
})
export class UserService {

  constructor(private _http : HttpClient) { }

  

  public loginUserFromRemote(user: User): Observable<any> {
   return this._http.post<any>("http://localhost:8080/login", user)
  }

  public registerUserFromRemote(user: User): Observable<any> {
    return this._http.post<any>("http://localhost:8080/registeruser", user)
   }

   handleError(_error: Response) {

   }

   public registerBookingDetails(bookingDetails:BookingDetails):Observable<BookingDetails>{
     return this._http.post<any>("http://localhost:8080/booking", bookingDetails)

   }
   public getBookingDetails():Observable<BookingDetails[]>{
    return this._http.get<BookingDetails[]>("http://localhost:8080/getCurrentBookings" )

  }

  public saveDriverInfo(driverInfo:IDriver):Observable<any>{
    var response: any = {};
    return of(response);  
   //return this._http.post<any>("http://localhost:8080/saveDriver",driverInfo)

  }

}
