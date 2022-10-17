import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { HttpClient } from '@angular/common/http';
import { User } from './user';
import { of } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class RegisterationService {

  constructor(private _http : HttpClient) { }

  public loginUserFromRemote(user: User): Observable<any> {
    
    var response: any = {};
    return of(response);

  }

  public registerUserFromRemote(user: User): Observable<any> {

    var response: any = {};
    return of(response);
   }

   handleError(_error: Response) {

   }

   public writeUserDataToFile(data: any){
    
   }
}
