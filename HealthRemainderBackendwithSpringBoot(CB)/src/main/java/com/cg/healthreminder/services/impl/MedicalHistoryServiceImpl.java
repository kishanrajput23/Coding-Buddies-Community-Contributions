package com.cg.healthreminder.services.impl;

/* @author Naman Bhandari*/

import java.util.List;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.cg.healthreminder.dao.MedicalHistoryDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.MedicalHistory;
import com.cg.healthreminder.services.MedicalHistoryService;

import javax.transaction.Transactional;
@Service
@Transactional
public class MedicalHistoryServiceImpl implements MedicalHistoryService{
	//Dao object created
	@Autowired
	private MedicalHistoryDao medicalHistoryDao;
	private static final Logger logger=LogManager.getLogger(MedicalHistoryServiceImpl.class);

	/* To validate medical history*/
	private String validateMedHistory(MedicalHistory m) {
		String msg;
		if(m.getPatientId()<0)
			msg="PatientId should be more than or equal to 0";
		else msg="Validated";
		return msg;
	}
	
	/*@Get
	 * To get all medical history records for a patient*/
	public List<MedicalHistory> getByPatientId(int id) throws AllCustomException{
		logger.info("Fetching medical records by patientid");
		List<MedicalHistory> mhlst= medicalHistoryDao.findRecordsByPatientId(id);
		if(mhlst.size()>0) {
			return mhlst;
		}
		else {
			throw new AllCustomException("No records found");
		}
		
	}
	/*@Post
	 * To add new medical record*/
	public MedicalHistory addRecord(MedicalHistory m) throws AllCustomException{
		logger.info("adding new medical record");
		String msg = validateMedHistory(m);
		if(msg.equals("Validated"))
			return medicalHistoryDao.save(m);
		else throw new AllCustomException(msg);
	}
	
	/*@Delete
	 * To delete a record*/
	public void deleteRecord(String file) {
		logger.info("deleteing medical record");
		medicalHistoryDao.deleteById(file);
	}
	
	/*@Put
	 * To update a record*/
	public MedicalHistory updateRecord(MedicalHistory m) throws AllCustomException{
		logger.info("updating medical record");
		String msg = validateMedHistory(m);
		if(msg.equals("Validated"))
			return medicalHistoryDao.save(m);
		else throw new AllCustomException(msg);
	}
}
