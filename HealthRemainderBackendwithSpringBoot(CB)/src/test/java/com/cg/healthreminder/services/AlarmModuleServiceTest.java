/**
 * @AnkitBanerjee
 * 
 * This is the Service Testing Class for Alarm Module.
*/
package com.cg.healthreminder.services;


import static org.assertj.core.api.Assertions.assertThat;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.dao.AlarmModuleDao;
import com.cg.healthreminder.model.AlarmModule;


@RunWith(SpringRunner.class)
@SpringBootTest
public class AlarmModuleServiceTest {

	@MockBean
    private AlarmModuleDao alarmModuleDao;

	@Autowired
    private AlarmModuleService alarmModuleService;
    
	/**
	 * 
	 * To check if a new Alarm Module gets created
	*/
	@Test
    public void testCreateAlarmModule() {
    	AlarmModule a= new AlarmModule();
    	a.setAlarmId(103);
    	a.setPatientId(1001);
    	a.setAlarmName("Back Medicine");
    	a.setAlarmDate(null);
    	a.setAlarmTime(null);
    	a.setAlarmNotes("Take the medicine after dinner");
		 
    	Mockito.when(alarmModuleDao.save(a)).thenReturn(a);
        assertThat(alarmModuleService.createAlarm(a)).isEqualTo(a);
    }
	
	/**
	 * 
	 * To check if we able to find Alarm Module using alarm name
	*/
	@Test
    public void testGetAlarmModuleByName() throws Exception{
		AlarmModule alarm = new AlarmModule();
		alarm.setAlarmId(104);
		alarm.setPatientId(1002);
		alarm.setAlarmName("Lung Medicine");
		alarm.setAlarmDate(null);
		alarm.setAlarmTime(null);
		alarm.setAlarmNotes("Take Medicine regularly");
    	
		AlarmModule a2 = alarmModuleDao.findAlarmByName("Lung Medicine");
        Mockito.when(a2).thenReturn(alarm);
        assertThat(alarmModuleService.findAlarmByName("Lung Medicine")).isEqualTo(alarm);
    }
	
	/**
	 * 
	 * To check if we can get All Alarm Module
	*/
	@Test
    public void testGetAllAlarm() throws Exception{
		AlarmModule a1 = new AlarmModule();
		a1.setAlarmId(104);
		a1.setPatientId(1002);
		a1.setAlarmName("Lung Medicine");
		a1.setAlarmDate(null);
		a1.setAlarmTime(null);
		a1.setAlarmNotes("Take Medicine regularly");

		AlarmModule a2 = new AlarmModule();
		a2.setAlarmId(105);
		a2.setPatientId(1022);
		a2.setAlarmName("Fever Medicine");
		a2.setAlarmDate(null);
		a2.setAlarmTime(null);
		a2.setAlarmNotes("Take Medicine after lunch");
        
        List<AlarmModule> alarmList = new ArrayList<>();
        alarmList.add(a1);
        alarmList.add(a2);

        Mockito.when(alarmModuleDao.findAll()).thenReturn(alarmList);
        assertThat(alarmModuleService.getAllAlarms()).isEqualTo(alarmList);
    
    }
    
//	@Test
//    public void testGetAlarmModuleById() throws Exception{
//		AlarmModule alarm = new AlarmModule();
//		alarm.setAlarmId(104);
//		alarm.setPatientId(1002);
//		alarm.setAlarmName("Lung Medicine");
//		alarm.setAlarmDate(null);
//		alarm.setAlarmTime(null);
//		alarm.setAlarmNotes("Take Medicine regularly");
//    	
//		AlarmModule a2 = alarmModuleDao.findById(104).get();
//        Mockito.when(a2).thenReturn(alarm);
//        assertThat(alarmModuleService.findAlarmById(104)).isEqualTo(alarm);
//    }
	
	
}
