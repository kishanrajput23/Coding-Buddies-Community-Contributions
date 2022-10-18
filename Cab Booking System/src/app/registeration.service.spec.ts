import { TestBed } from '@angular/core/testing';

import { RegisterationService } from './registeration.service';

describe('RegisterationService', () => {
  let service: RegisterationService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(RegisterationService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
