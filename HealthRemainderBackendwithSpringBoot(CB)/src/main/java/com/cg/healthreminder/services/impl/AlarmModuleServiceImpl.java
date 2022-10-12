/**
 * @Ankit Banerjee
 * 
 * This is the Service Class for Alarm Module.
*/

package com.cg.healthreminder.services.impl;

import java.sql.Date;
import java.sql.Timestamp;
import java.util.Optional;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.cg.healthreminder.dao.AlarmModuleDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AlarmModule;

@Service
@Transactional
public class AlarmModuleServiceImpl implements com.cg.healthreminder.services.AlarmModuleService {
	
	public static final String EXCEP = "AlarmModule not found";
	
	@Autowired
	private AlarmModuleDao alarmModuleDao;
	private static final Logger logger=LogManager.getLogger(AlarmModuleServiceImpl.class);
	
	/**
	 * 
	 * To find Alarm Module by Alarm Id.
	*/
	@Override
	public AlarmModule findAlarmById(Integer id)  throws AllCustomException
	{
		logger.info("AlarmModuleServiceImpl: Finding Alarm details by Alarm Id ........");
		
		AlarmModule ob =  alarmModuleDao.findAlarmById(id);
		if(ob == null) {
			throw new AllCustomException(EXCEP);
		}
		
		return ob;
	}
	
	/**
	 * 
	 * To find Alarm Module by Alarm Name.
	*/
	@Override
	public AlarmModule findAlarmByName(String alarmName)  throws AllCustomException
	{
		logger.info("AlarmModuleServiceImpl: Finding Alarm Details by Name........");
		
		AlarmModule ob = alarmModuleDao.findAlarmByName(alarmName);
		if(ob == null) {
			throw new AllCustomException(EXCEP);
		}
		
		return ob;
	}
	
	/**
	 * 
	 * To get All Alarm Module.
	*/
	@Override
	public Iterable<AlarmModule> getAllAlarms()
	{
		logger.info("AlarmModuleServiceImpl: Retrieving ALl Alarm Modules ........");
		return alarmModuleDao.findAll();
	}
	
	/**
	 * 
	 * To Update Alarm Module by Alarm Id.
	*/
	@Override
	public AlarmModule updateAlarmById(Integer aid, Integer pid, String name, Timestamp alarmTime, Date alarmDate, String note) throws AllCustomException
	{
		logger.info("AlarmModuleServiceImpl: Updating Alarm Details using Alarm Id........");
		
		Optional<AlarmModule> alarmModules = alarmModuleDao.findById(aid);
		AlarmModule ob = null;
		
		if(alarmModules.isPresent()) {
			
			ob = alarmModules.get();
			ob.setAlarmName(name);
			ob.setAlarmTime(alarmTime);
			ob.setAlarmDate(alarmDate);
			ob.setAlarmNotes(note);
		}
		else
		{
			throw new AllCustomException(EXCEP);
		}
		
		return alarmModuleDao.save(ob);
	}
	
	/**
	 * 
	 * To dlete Alarm Module by Alarm Id.
	*/
	@Override
	public AlarmModule deleteAlarmById(Integer id)  throws AllCustomException
	{
		logger.info("AlarmModuleServiceImpl: Deleting Alarm details by Alarm Id ........");
		
		Optional<AlarmModule> alarmModule = alarmModuleDao.findById(id);
		AlarmModule ob = null;
		if(alarmModule.isPresent()) {
			
			ob = alarmModule.get();
			alarmModuleDao.delete(ob);
		}
		else {
			throw new AllCustomException(EXCEP);
			
		}
		
		return ob;
	}
	
	/**
	 * 
	 * To create Alarm Module by Alarm Id.
	*/
	@Override
	public AlarmModule createAlarm(AlarmModule alarmModule)
	{
		logger.info("AlarmModuleServiceImpl: Creating Alarm details ........");
		
		return alarmModuleDao.save(alarmModule);
	}
	
	
}
