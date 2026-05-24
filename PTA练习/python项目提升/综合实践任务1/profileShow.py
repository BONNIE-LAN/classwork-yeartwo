def profileShow():
    name=input("请输入您的姓名：")
    location=input("请输入您的地点：")
    hobby=input("请输入您的爱好：")
    print("亲爱的{},你好!根据您反馈的信息,我猜想您会是一个喜欢在{}{}的人".format(name,location,hobby))
profileShow()