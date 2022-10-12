package com.cg.healthreminder.services;

// @author Naman Bhandari

import java.util.List;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.Patient;

public interface PatientService {
	public List<Patient> getAllPatients();
	public Patient getPatient(int id) throws AllCustomException;
	public Patient addPatient(Patient p) throws AllCustomException;
	public Patient updatePatient(Patient p) throws AllCustomException;
	public Integer deletePatientById(int id);
}
