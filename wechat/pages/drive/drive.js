Page({

  /**
   * 页面的初始数据
   */
  data: {
    ipPort : "",
    // postUrl: "http://192.168.1.30:9001"
    postURL: ""
  },
  /**
   * 小车移动函数
   * 根据按钮获取指令参数(data-direction),并将指令发送到服务器端
   */  
  carMove: function(event) {
    console.log("postUrl:"+ this.data.postURL)
    wx.request({
      url: this.data.postURL,      
      data: {
        cmd:event.currentTarget.dataset.direction
      },     
      method: "GET",     
      success: function(res) {
        console.log("success")
      },
      fail: function(res) {
        console.log("fail")
      }
    })
  },
  carStop: function(event) {
    wx.request({
      url: this.data.postURL,
      data: {
        cmd: "S"
      },     
      method: "GET",
      success: function(res) {
        console.log("success")
      },
      fail: function(res) {
        console.log("fail")
      }
    })
  },
  connectBtnClick:function(e) {
    if(this.data.ipPort.length <= 7 || this.data.ipPort.length > 20) {
      console.log("invalid");
    } else {
      this.setData({
        postURL : "http://" + this.data.ipPort
      })
    }
  },
  ipPortInput:function(e) {
    this.setData({
      ipPort: e.detail.value
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  // onLoad: function(options) {    
  //   this.setData({     
  //     postURL: "http://192.168.1.30:9001"
  //   })    
  //   console.log("post url in control page: " + this.data.postURL)
  // },
})