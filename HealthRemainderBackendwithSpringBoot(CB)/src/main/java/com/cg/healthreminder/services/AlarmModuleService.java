/**
 * @Ankit Banerjee
 *
 * Interface for AlarmModule which contains various services provided.
 */
package com.cg.healthreminder.services;

import java.sql.*;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AlarmModule;

public interface AlarmModuleService {
	
	AlarmModule findAlarmById(Integer id)  throws AllCustomException;
	AlarmModule findAlarmByName(String alarmName)  throws AllCustomException;
	Iterable<AlarmModule> getAllAlarms()  throws AllCustomException;
	AlarmModule updateAlarmById(Integer aid, Integer pid, String name, Timestamp alarmTime, Date alarmDate, String note)  throws AllCustomException;
	AlarmModule deleteAlarmById(Integer id)  throws AllCustomException;
	AlarmModule createAlarm(AlarmModule alarmModule);
	
}
