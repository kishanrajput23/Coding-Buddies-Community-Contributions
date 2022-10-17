import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DriverridesComponent } from './driverrides.component';

describe('DriverridesComponent', () => {
  let component: DriverridesComponent;
  let fixture: ComponentFixture<DriverridesComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DriverridesComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DriverridesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
