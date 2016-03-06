package vliu.mina;
import java.util.Date;

import org.apache.mina.core.service.IoHandlerAdapter;
import org.apache.mina.core.session.IdleStatus;
import org.apache.mina.core.session.IoSession;

public class ServerHandler extends IoHandlerAdapter{
	
	@Override
	public void sessionCreated(IoSession session) {
		System.out.println(session.getRemoteAddress().toString());
	} 
	
	@Override
	public void exceptionCaught(IoSession session, Throwable cause)throws Exception{
		cause.printStackTrace();
	}
	
	@Override
	public void messageReceived(IoSession session,Object message) throws Exception{
		System.out.println("recv: "+message.toString());
		
		String str = message.toString();
		if( str.trim().equalsIgnoreCase("quit") ) {
		    session.close(true);
		    return;
		}
		
		Date date = new Date();
		session.write( date.toString() );
		System.out.println("send: "+date.toString());
	}
	
	@Override
    public void sessionIdle( IoSession session, IdleStatus status ) throws Exception{
        System.out.println( "IDLE " + session.getIdleCount( status ));
    }
}

