import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DriverhomeComponent } from './driverhome.component';

describe('DriverhomeComponent', () => {
  let component: DriverhomeComponent;
  let fixture: ComponentFixture<DriverhomeComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DriverhomeComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DriverhomeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
