import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Hospital } from '../interfaces/hospital';

@Injectable({
  providedIn: 'root'
})
export class PatientService {
  private REST_API_SERVER = "http://localhost:3000/hospitals";

  constructor(private httpClient: HttpClient) { }

  public sendGetRequest(): Observable<Hospital> {
    return this.httpClient.get<Hospital>(this.REST_API_SERVER);
  }

  public getById(id: number): Observable<Hospital> {
    return this.httpClient.get<Hospital>(`${this.REST_API_SERVER}/${id}`);
  }

  public getHospitalByName(name:string): Observable<Hospital>{
    return this.httpClient.get<Hospital>(`http://localhost:3000/hospitals?name=${name}`);
  }
}
