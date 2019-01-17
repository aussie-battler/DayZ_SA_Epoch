/*
	Epoch Mod for DayZ Standalone
	
	FileName: CreditsLoader.c

	Authors: DayZ SA Epoch Dev Team and Community Contributors
	https://github.com/EpochModTeam/DayZ_SA_Epoch/blob/experimental/README.md	
	
	Licensing:
	https://github.com/EpochModTeam/DayZ_SA_Epoch/blob/experimental/LICENSE.md

	Changelog:

	[1/16/2019] AWOL / DirtySanchez
		AWOL1 - DZSA Epoch Dev Team and Community Credits
		
	[NewDate] Author(s)
		Initials(Change#)-Description
*/
modded class CreditsLoader
{
	protected static const string JSON_FILE_PATH_EPOCH = "emt/dzsa_epoch_assets/AWOL/Json/credits.json";
	
	override static void CreateTestJson()
	{
		string test_name_department	= "Department";
		string test_name_setion		= "Section";
		string test_name_line		= "Line";
		
		JsonDataCredits data = new JsonDataCredits;
		data.Departments = new array<ref JsonDataCreditsDepartment>;
		
		for( int index_dep = 0; index_dep < 3; ++index_dep )
		{
			ref JsonDataCreditsDepartment data_department = new JsonDataCreditsDepartment;
			data_department.Sections = new array<ref JsonDataCreditsSection>;			
			data_department.DepartmentName = (test_name_department +" "+ index_dep);			
			
			for( int index_sec = 0; index_sec < 4; ++index_sec )
			{
				ref JsonDataCreditsSection data_section = new JsonDataCreditsSection;
				data_section.SectionLines = new array<string>;
				data_section.SectionName = (test_name_setion +" "+ index_sec);
				
				int lines_count = Math.RandomInt(3, 10);
				for( int i = 0; i < lines_count; ++i )
				{
					data_section.SectionLines.Insert( test_name_line +" "+ i );
				}	
				
				data_department.Sections.Insert( data_section );
			}
			
			data.Departments.Insert( data_department );
		}
		
		JsonFileLoader<ref JsonDataCredits>.JsonSaveFile( JSON_FILE_PATH_EPOCH, data );
	}
	
	override static JsonDataCredits GetData()
	{
		ref JsonDataCredits data;
		JsonFileLoader<ref JsonDataCredits>.JsonLoadFile( JSON_FILE_PATH_EPOCH, data );
		
		return data;
	}
}
