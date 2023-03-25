#include<iostream>
#include<string>
using namespace std;
/*                                  多态训练
    电脑组件：CPU，显卡，内存条
            计算，显示，储存
    每个零件抽象基类，不同厂商：Intel，Lenovo
    提供电脑工作函数，调用每个零件工作接口
    测试组装三台电脑
 */

//零件层，都抽象纯虚函数，基类（多态）
class CPU
{
private:
    /* data */
public:
    virtual void calculate() = 0;   //抽象纯虚函数
    virtual ~CPU(){}
};
class VideoCard
{
private:
    /* data */
public:
    virtual void display() = 0;   //抽象纯虚函数
    virtual ~VideoCard(){}
};
class Memory
{
private:
    /* data */
public:
    virtual void storage() = 0;   //抽象纯虚函数
    virtual ~Memory (){}
};

//电脑类，三个指针接收零件，通过函数使零件工作
class PC
{
private:
    CPU * m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
public:
    PC(CPU *cpu,VideoCard *vc,Memory *mem); //（多态）
    void work();        //父类指针 调用接口
    ~PC(){              //手动 释放电脑三零件
        if(m_cpu != NULL || m_mem != NULL || m_vc != NULL){
            delete m_cpu;
            m_cpu = NULL;
            delete m_mem;
            m_mem = NULL;
            delete m_vc;
            m_vc = NULL;
        }
    }
};

class IntelCPU :public CPU
{
private:
    /* data */
public:
    virtual void calculate() {
        cout<<"IntelCPU is Calculating..."<<endl;
    }
};
class IntelVideoCard :public VideoCard
{
private:
    /* data */
public:
    virtual void display() {
        cout<<"IntelVideoCard is displaying..."<<endl;
    }
};
class IntelMemory :public Memory
{
private:
    /* data */
public:
    virtual void storage() {
        cout<<"IntelMemory is storaging..."<<endl;
    }
};

class LenovoCPU :public CPU
{
private:
    /* data */
public:
    virtual void calculate() {
        cout<<"LenovoCPU is Calculating..."<<endl;
    }
};
class LenovoVideoCard :public VideoCard
{
private:
    /* data */
public:
    virtual void display() {
        cout<<"LenovoVideoCard is displaying..."<<endl;
    }
};
class LenovoMemory :public Memory
{
private:
    /* data */
public:
    virtual void storage() {
        cout<<"LenovoMemory is storaging..."<<endl;
    }
};


PC::PC(CPU *cpu,VideoCard *vc,Memory *mem)
{
    m_cpu = cpu;
    m_vc = vc;
    m_mem = mem;
}
void PC::work(){
    m_cpu->calculate();
    m_vc->display();
    m_mem->storage();
}

void test01(){
    CPU * intelCPU = new IntelCPU;
    VideoCard * videoCard = new IntelVideoCard;
    Memory * memory = new IntelMemory;

    cout<<"PC1----------------------"<<endl;
    PC * pc = new PC(intelCPU,videoCard,memory);
    pc->work();
    delete pc;

    cout<<"PC2----------------------"<<endl;
    pc = new PC(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
    pc->work();
    delete pc;

    cout<<"PC3----------------------"<<endl;
    pc = new PC(new IntelCPU,new LenovoVideoCard,new IntelMemory);
    pc->work();
    delete pc;
}

int main(){
    test01();
}