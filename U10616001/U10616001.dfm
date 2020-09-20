object Form1: TForm1
  Left = 296
  Top = 130
  Width = 1152
  Height = 647
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GLBox1: TGLBox
    Left = 24
    Top = 32
    Width = 577
    Height = 537
    OnGLInit = init
    OnGLDraw = Draw
  end
  object GroupBox1: TGroupBox
    Left = 624
    Top = 32
    Width = 257
    Height = 121
    Caption = #26059#36681#65288#21934#20301#28858#35282#24230#65289
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 19
      Height = 13
      Caption = 'X'#36600
    end
    object Label2: TLabel
      Left = 16
      Top = 56
      Width = 19
      Height = 13
      Caption = 'Y'#36600
    end
    object Label3: TLabel
      Left = 16
      Top = 88
      Width = 19
      Height = 13
      Caption = 'Z'#36600
    end
    object Labelrx: TLabel
      Left = 184
      Top = 24
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Labelry: TLabel
      Left = 184
      Top = 56
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Labelrz: TLabel
      Left = 184
      Top = 88
      Width = 6
      Height = 13
      Caption = '0'
    end
    object ScrollBarrx: TScrollBar
      Left = 40
      Top = 24
      Width = 137
      Height = 17
      Max = 359
      Min = -359
      PageSize = 0
      TabOrder = 0
      OnScroll = Scrollrx
    end
    object ScrollBarry: TScrollBar
      Left = 40
      Top = 56
      Width = 137
      Height = 17
      Max = 359
      Min = -359
      PageSize = 0
      TabOrder = 1
      OnScroll = Scrollry
    end
    object ScrollBarrz: TScrollBar
      Left = 40
      Top = 88
      Width = 137
      Height = 17
      Max = 359
      Min = -359
      PageSize = 0
      TabOrder = 2
      OnScroll = Scrollrz
    end
    object Buttonr: TButton
      Left = 208
      Top = 16
      Width = 33
      Height = 97
      Caption = #37325#32622
      TabOrder = 3
      OnClick = Btnr
    end
  end
  object GroupBox2: TGroupBox
    Left = 624
    Top = 168
    Width = 257
    Height = 121
    Caption = #24179#31227#65288#21934#20301#28858'0.1'#65289
    TabOrder = 2
    object Label4: TLabel
      Left = 16
      Top = 24
      Width = 19
      Height = 13
      Caption = 'X'#36600
    end
    object Label5: TLabel
      Left = 16
      Top = 56
      Width = 19
      Height = 13
      Caption = 'Y'#36600
    end
    object Label6: TLabel
      Left = 16
      Top = 88
      Width = 19
      Height = 13
      Caption = 'Z'#36600
    end
    object Labeltx: TLabel
      Left = 184
      Top = 24
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Labelty: TLabel
      Left = 184
      Top = 56
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Labeltz: TLabel
      Left = 184
      Top = 88
      Width = 6
      Height = 13
      Caption = '0'
    end
    object ScrollBartx: TScrollBar
      Left = 40
      Top = 24
      Width = 137
      Height = 17
      Min = -100
      PageSize = 0
      TabOrder = 0
      OnScroll = Scrolltx
    end
    object ScrollBarty: TScrollBar
      Left = 40
      Top = 56
      Width = 137
      Height = 17
      Min = -100
      PageSize = 0
      TabOrder = 1
      OnScroll = Scrollty
    end
    object ScrollBartz: TScrollBar
      Left = 40
      Top = 88
      Width = 137
      Height = 17
      Min = -100
      PageSize = 0
      TabOrder = 2
      OnScroll = Scrolltz
    end
    object Buttont: TButton
      Left = 208
      Top = 16
      Width = 33
      Height = 97
      Caption = #37325#32622
      TabOrder = 3
      OnClick = Btnt
    end
  end
  object GroupBox3: TGroupBox
    Left = 624
    Top = 304
    Width = 257
    Height = 145
    Caption = #32302#25918#65288#21934#20301#28858#30334#20998#27604#65289
    TabOrder = 3
    object Labelsx: TLabel
      Left = 184
      Top = 24
      Width = 18
      Height = 13
      Caption = '100'
    end
    object Labelsy: TLabel
      Left = 184
      Top = 56
      Width = 18
      Height = 13
      Caption = '100'
    end
    object Labelsz: TLabel
      Left = 184
      Top = 88
      Width = 18
      Height = 13
      Caption = '100'
    end
    object Label7: TLabel
      Left = 16
      Top = 24
      Width = 19
      Height = 13
      Caption = 'X'#36600
    end
    object Label8: TLabel
      Left = 16
      Top = 56
      Width = 19
      Height = 13
      Caption = 'Y'#36600
    end
    object Label9: TLabel
      Left = 16
      Top = 88
      Width = 19
      Height = 13
      Caption = 'Z'#36600
    end
    object Buttons: TButton
      Left = 208
      Top = 16
      Width = 33
      Height = 97
      Caption = #37325#32622
      TabOrder = 0
      OnClick = Btns
    end
    object ScrollBarsx: TScrollBar
      Left = 40
      Top = 24
      Width = 137
      Height = 17
      Max = 200
      PageSize = 0
      Position = 100
      TabOrder = 1
      OnScroll = Scrollsx
    end
    object ScrollBarsy: TScrollBar
      Left = 40
      Top = 56
      Width = 137
      Height = 17
      Max = 200
      PageSize = 0
      Position = 100
      TabOrder = 2
      OnScroll = Scrollsy
    end
    object ScrollBarsz: TScrollBar
      Left = 40
      Top = 88
      Width = 137
      Height = 17
      Max = 200
      PageSize = 0
      Position = 100
      TabOrder = 3
      OnScroll = Scrollsz
    end
    object CheckBoxs: TCheckBox
      Left = 48
      Top = 120
      Width = 97
      Height = 17
      Caption = #31561#27604#20363#32302#25918
      TabOrder = 4
      OnClick = Checks
    end
  end
  object GroupBox4: TGroupBox
    Left = 624
    Top = 464
    Width = 441
    Height = 97
    Caption = #38568#36984#38914#40670#35222#35282
    TabOrder = 4
    object Buttoni1: TButton
      Left = 16
      Top = 24
      Width = 97
      Height = 25
      Caption = #65288'1,1,1'#65289#38928#35373
      TabOrder = 0
      OnClick = Buttoni1Click
    end
    object Buttoni2: TButton
      Left = 120
      Top = 24
      Width = 97
      Height = 25
      Caption = #65288'-1,1,1'#65289
      TabOrder = 1
      OnClick = Buttoni2Click
    end
    object Buttoni3: TButton
      Left = 224
      Top = 24
      Width = 97
      Height = 25
      Caption = #65288'-1,1,-1'#65289
      TabOrder = 2
      OnClick = Buttoni3Click
    end
    object Buttoni4: TButton
      Left = 328
      Top = 24
      Width = 97
      Height = 25
      Caption = #65288'1,1,-1'#65289
      TabOrder = 3
      OnClick = Buttoni4Click
    end
    object Buttoni5: TButton
      Left = 16
      Top = 56
      Width = 97
      Height = 25
      Caption = #65288'1,-1,-1'#65289
      TabOrder = 4
      OnClick = Buttoni5Click
    end
    object Buttoni6: TButton
      Left = 120
      Top = 56
      Width = 97
      Height = 25
      Caption = #65288'1,-1,1'#65289
      TabOrder = 5
      OnClick = Buttoni6Click
    end
    object Buttoni7: TButton
      Left = 224
      Top = 56
      Width = 97
      Height = 25
      Caption = #65288'-1,-1,1'#65289
      TabOrder = 6
      OnClick = Buttoni7Click
    end
    object Buttoni8: TButton
      Left = 328
      Top = 56
      Width = 97
      Height = 25
      Caption = #65288'-1,-1,-1'#65289
      TabOrder = 7
      OnClick = Buttoni8Click
    end
  end
  object GroupBox5: TGroupBox
    Left = 896
    Top = 320
    Width = 185
    Height = 57
    Caption = #25171#20809
    TabOrder = 5
    object CheckBoxlr: TCheckBox
      Left = 8
      Top = 24
      Width = 49
      Height = 17
      Caption = #32005#20809
      Checked = True
      State = cbChecked
      TabOrder = 0
      OnClick = CheckBoxlrClick
    end
    object CheckBoxlg: TCheckBox
      Left = 64
      Top = 24
      Width = 49
      Height = 17
      Caption = #32160#20809
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = CheckBoxlgClick
    end
    object CheckBoxlb: TCheckBox
      Left = 120
      Top = 24
      Width = 49
      Height = 17
      Caption = #34253#20809
      Checked = True
      State = cbChecked
      TabOrder = 2
      OnClick = CheckBoxlbClick
    end
  end
  object GroupBox7: TGroupBox
    Left = 896
    Top = 32
    Width = 185
    Height = 129
    Caption = #29289#20214
    TabOrder = 6
    object Buttoninput: TButton
      Left = 8
      Top = 24
      Width = 169
      Height = 25
      Caption = #36617#20837#36039#26009#65288#36969#29992#33290'model'#65289
      TabOrder = 0
      OnClick = ButtoninputClick
    end
    object Buttonobj1: TButton
      Left = 8
      Top = 56
      Width = 169
      Height = 25
      Caption = #24425#33394#28472#23652#31435#26041#39636#65288#38928#35373#65289
      TabOrder = 1
      OnClick = Buttonobj1Click
    end
    object Buttonobj2: TButton
      Left = 8
      Top = 88
      Width = 169
      Height = 25
      Caption = #24425#33394#31435#26041#39636
      TabOrder = 2
      OnClick = Buttonobj2Click
    end
  end
  object GroupBox6: TGroupBox
    Left = 896
    Top = 176
    Width = 185
    Height = 57
    Caption = #26448#36074#65288'Kangaroo'#26368#26126#39023#65289
    TabOrder = 7
    object RadioBrass: TRadioButton
      Left = 56
      Top = 24
      Width = 49
      Height = 17
      Caption = #38738#37509
      TabOrder = 0
      OnClick = RadioBrassClick
    end
    object RadioGold: TRadioButton
      Left = 104
      Top = 24
      Width = 49
      Height = 17
      Caption = #37329
      TabOrder = 1
      OnClick = RadioGoldClick
    end
    object RadioPewter: TRadioButton
      Left = 144
      Top = 24
      Width = 33
      Height = 17
      Caption = #37675
      TabOrder = 2
      OnClick = RadioPewterClick
    end
    object Radiodefault: TRadioButton
      Left = 8
      Top = 24
      Width = 49
      Height = 17
      Caption = #38928#35373
      Checked = True
      TabOrder = 3
      TabStop = True
      OnClick = RadiodefaultClick
    end
  end
  object GroupBox8: TGroupBox
    Left = 896
    Top = 392
    Width = 185
    Height = 57
    Caption = #33879#33394#26041#24335
    TabOrder = 8
    object RadioLine: TRadioButton
      Left = 120
      Top = 24
      Width = 49
      Height = 17
      Caption = #32218#26781
      TabOrder = 0
      OnClick = RadioLineClick
    end
    object RadioFlat: TRadioButton
      Left = 64
      Top = 24
      Width = 49
      Height = 17
      Caption = #24179#38754
      TabOrder = 1
      OnClick = RadioFlatClick
    end
    object RadioSmooth: TRadioButton
      Left = 8
      Top = 24
      Width = 49
      Height = 17
      Caption = #24179#28369
      Checked = True
      TabOrder = 2
      TabStop = True
      OnClick = RadioSmoothClick
    end
  end
  object GroupBox9: TGroupBox
    Left = 896
    Top = 248
    Width = 185
    Height = 57
    Caption = #35222#31383
    TabOrder = 9
    object Radiovs: TRadioButton
      Left = 32
      Top = 24
      Width = 49
      Height = 17
      Caption = #21934#20491
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadiovsClick
    end
    object Radiovm: TRadioButton
      Left = 104
      Top = 24
      Width = 49
      Height = 17
      Caption = #22810#20491
      TabOrder = 1
      OnClick = RadiovmClick
    end
  end
  object OD: TOpenDialog
    Left = 8
    Top = 584
  end
end
