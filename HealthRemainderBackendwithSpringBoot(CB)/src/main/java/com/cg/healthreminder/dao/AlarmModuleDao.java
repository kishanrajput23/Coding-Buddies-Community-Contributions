/**
 * @Ankit Banerjee
 *
 * This is the DAO class for Alarm Module
 */
package com.cg.healthreminder.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.AlarmModule;


@Repository
public interface AlarmModuleDao extends JpaRepository<AlarmModule,Integer>{

	@Query("select a from AlarmModule a where a.alarmId=:alarmId")
	AlarmModule findAlarmById(@Param("alarmId")Integer alarmId);
	
	@Query("select a from AlarmModule a where a.alarmName=:alarmName")
	AlarmModule findAlarmByName(@Param("alarmName")String alarmName);
	
	@Query("select a from AlarmModule a where a.patientId=:patientId")
	AlarmModule findByPatientId(@Param("patientId")int patientId);
}
