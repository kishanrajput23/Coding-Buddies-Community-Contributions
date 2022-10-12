/**
 * @SayantanDas
 * 
 * This is the DAO Repository interface for AppointmentDetails
 * It also contains few custom queries.
*/


package com.cg.healthreminder.dao;


import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.AppointmentDetails;
@Repository
public interface AppointmentDetailsJpaDao extends JpaRepository<AppointmentDetails,Integer>{
	  @Query("select a from AppointmentDetails a where a.patientId=:patientId")
	  AppointmentDetails findByPatientId(@Param("patientId")int patientId);
	  
	  @Query("select a from AppointmentDetails a where a.doctorId=:doctorId")
	  AppointmentDetails findByDoctorId(@Param("doctorId")int doctorId);
}
