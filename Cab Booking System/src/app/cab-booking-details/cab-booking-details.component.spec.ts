import { ComponentFixture, TestBed } from '@angular/core/testing';

import { CabBookingDetailsComponent } from './cab-booking-details.component';

describe('CabBookingDetailsComponent', () => {
  let component: CabBookingDetailsComponent;
  let fixture: ComponentFixture<CabBookingDetailsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ CabBookingDetailsComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(CabBookingDetailsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
