import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DriverregisterComponent } from './driverregister.component';

describe('DriverregisterComponent', () => {
  let component: DriverregisterComponent;
  let fixture: ComponentFixture<DriverregisterComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DriverregisterComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DriverregisterComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
