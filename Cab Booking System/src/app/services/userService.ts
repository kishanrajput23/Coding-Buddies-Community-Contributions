import { HttpClient } from '@angular/common/http';
import { jsDocComment } from '@angular/compiler';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { IDriver } from 'src/driver';
import { BookingDetails } from '../bookingDetails';
import { User } from '../user'

@Injectable({
  providedIn: 'root'
})
export class UserService {

  constructor(private _http : HttpClient) { }

  

  public registeerUser(user: User): Observable<any> {
   return this._http.post<any>("http://localhost:3000/users", user);
  }

  public  loginUsers(user: any): Observable<any>{
    return this._http.get<any>("http://localhost:3000/users");
  }

  public getRideDetails(rideId: number){
    return this._http.get<any>("http://localhost:3000/rides/"+rideId);
  }

  public cancelRide(rideId: number){
    return this._http.put<any>("http://localhost:3000/rides/"+rideId,'{"Status":"Cancelled"}');
  }

  public bookRide(bookRide: BookingDetails): Observable<any>{
    var userContext: User= JSON.parse(localStorage.getItem('userContext')|| '{}')
    bookRide.userName=userContext.firstname+' '+ userContext.lastname;
    return this._http.post<any>("http://localhost:3000/rides",bookRide);
  }
}
