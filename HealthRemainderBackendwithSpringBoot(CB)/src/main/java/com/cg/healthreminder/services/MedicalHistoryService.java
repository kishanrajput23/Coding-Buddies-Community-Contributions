package com.cg.healthreminder.services;

/* @author Naman Bhandari*/

import java.util.List;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.MedicalHistory;

public interface MedicalHistoryService {
public List<MedicalHistory> getByPatientId(int id) throws AllCustomException;
public MedicalHistory addRecord(MedicalHistory m) throws AllCustomException;
public void deleteRecord(String file);
public MedicalHistory updateRecord(MedicalHistory m) throws AllCustomException;
}
