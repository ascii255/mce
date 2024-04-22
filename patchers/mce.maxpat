{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 6,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 59.0, 119.0, 640.0, 480.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 421.0, 196.0, 53.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 421.0, 196.0, 53.0, 20.0 ],
					"text" : "helpfiles"
				}

			}
, 			{
				"box" : 				{
					"button" : 1,
					"htabcolor" : [ 0.501960784313725, 0.501960784313725, 0.501960784313725, 1.0 ],
					"id" : "obj-30",
					"maxclass" : "tab",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 348.0, 224.0, 197.0, 30.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 348.0, 224.0, 197.0, 30.0 ],
					"tabs" : [ "mce.onepole~" ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 444.0, 352.0, 79.0, 22.0 ],
					"text" : "prepend help"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 444.0, 404.0, 51.0, 22.0 ],
					"text" : "pcontrol"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 57.0, 298.0, 50.0, 22.0 ],
					"text" : "select 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 57.0, 330.0, 284.0, 35.0 ],
					"text" : ";\rmax launchbrowser https://github.com/ascii255/mce"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 57.0, 377.0, 50.0, 22.0 ],
					"text" : "select 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 154.0, 196.0, 73.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 154.0, 196.0, 73.0, 20.0 ],
					"text" : "GitHub links"
				}

			}
, 			{
				"box" : 				{
					"button" : 1,
					"htabcolor" : [ 0.501960784313725, 0.501960784313725, 0.501960784313725, 1.0 ],
					"id" : "obj-12",
					"maxclass" : "tab",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 92.0, 224.0, 198.0, 60.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 92.0, 224.0, 198.0, 60.0 ],
					"tabs" : [ "repository", "wiki" ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 57.0, 411.0, 307.0, 35.0 ],
					"text" : ";\rmax launchbrowser https://github.com/ascii255/mce/wiki"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 70.0, 139.0, 371.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 70.0, 139.0, 371.0, 22.0 ],
					"text" : "This is a Max package example containing a onepole filter."
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 18.0,
					"id" : "obj-4",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 240.0, 55.0, 307.0, 47.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 240.0, 55.0, 307.0, 47.0 ],
					"text" : "Music Creativity and the Environment\nTokyo University of Arts"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 64.0,
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 71.0, 39.0, 151.0, 78.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 71.0, 39.0, 151.0, 78.0 ],
					"text" : "MCE"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"order" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"order" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-30", 1 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
