import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class BedBookingService {


  private BOOKING_URL = "http://localhost:3000/bookings";

  constructor(private http: HttpClient) { }

  public bookAppointment(booking: any) {
    console.log("Service");
    return this.http.post(this.BOOKING_URL, booking);
  }
}
