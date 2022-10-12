package com.cg.healthreminder.dao;

/* @author Naman Bhandari*/

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.MedicalHistory;
@Repository
public interface MedicalHistoryDao extends JpaRepository<MedicalHistory,String>{
	@Query("select m from MedicalHistory m where m.patientId=:id")
	List<MedicalHistory> findRecordsByPatientId(int id);
}
